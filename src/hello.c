/* hello.c
 *
 * Copyright (C) 1999 Havoc Pennington
 *
 * This program is free software; you can redistribute it and/or 
 * modify it under the terms of the GNU General Public License as 
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
 * USA
 */

#include <config.h>
#include <glib-object.h>
#include <gnome.h>
#include <glib/gi18n.h>

#include "app.h"


static void session_die  (GnomeClient* client, gpointer client_data);
static gint save_session (GnomeClient *client, gint phase, 
                          GnomeSaveStyle save_style,
                          gint is_shutdown, GnomeInteractStyle interact_style,
                          gint is_fast, gpointer client_data);


static int greet_mode = FALSE;
static char* message  = NULL;
static char* geometry = NULL;

struct poptOption options[] = {
  {
    "greet",
    'g',
    POPT_ARG_NONE,
    &greet_mode,
    0,
    N_("Say hello to specific people listed on the command line"),
    NULL
  },
  { 
    "message",
    'm',
    POPT_ARG_STRING,
    &message,
    0,
    N_("Specify a message other than \"Hello, World!\""),
    N_("MESSAGE")
  },
  { 
    "geometry",
    '\0',
    POPT_ARG_STRING,
    &geometry,
    0,
    N_("Specify the geometry of the main window"),
    N_("GEOMETRY")
  },
  POPT_TABLEEND
};

int 
main (int argc, char **argv)
{
  GtkWidget *app;
  GnomeProgram *gnome_hello;
  GnomeClient *client;
  GValue value = {0,};
  poptContext pctx; 
  GSList *greet = NULL;
  char **args;
  int i;

  bindtextdomain (GETTEXT_PACKAGE, GNOMELOCALEDIR);  
  bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");
  textdomain (GETTEXT_PACKAGE);

  gnome_hello = gnome_program_init (PACKAGE, VERSION, LIBGNOMEUI_MODULE,
				    argc, argv, 
				    GNOME_PARAM_POPT_TABLE, options, 
				    GNOME_PARAM_APP_DATADIR,DATADIR, NULL);
  gtk_window_set_default_icon_name ("gnome-hello-logo");

  g_value_init (&value, G_TYPE_POINTER);
  g_object_get_property (G_OBJECT(gnome_hello), 
			 GNOME_PARAM_POPT_CONTEXT, &value);
  
  pctx = (poptContext) g_value_get_pointer (&value);

  args = (char **) poptGetArgs(pctx);

  if (greet_mode && args)
    {
      i = 0;
      while (args[i] != NULL) 
        {
          greet = g_slist_prepend (greet, args[i]);
          ++i;
        } 
      
      greet = g_slist_reverse (greet); 
    }
  else if (greet_mode && args == NULL)
    {
      g_printerr (_("You must specify someone to greet.\n"));
      return 1;
    }
  else if (args != NULL)
    {
      g_printerr (_("Command line arguments are only allowed with --greet.\n"));
      return 1;
    }
  else
    { 
      g_assert (!greet_mode && args == NULL);
    }

  poptFreeContext (pctx); 

  client = gnome_master_client ();
  g_signal_connect (G_OBJECT (client), "save_yourself",
                    G_CALLBACK (save_session), argv[0]);
  g_signal_connect (G_OBJECT (client), "die",
                    G_CALLBACK (session_die), NULL);
  
  app = hello_app_new (message, geometry, greet);

  g_slist_free (greet);

  gtk_widget_show_all(app);

  gtk_main();

  return 0;
}

static gint
save_session (GnomeClient       *client, 
              gint               phase, 
              GnomeSaveStyle     save_style,
              gint               is_shutdown, 
              GnomeInteractStyle interact_style,
              gint               is_fast, 
              gpointer           client_data)
{
  gchar **argv;
  guint argc;

  argv = g_new0 (gchar*, 4);
  argc = 0;

  argv[argc++] = client_data;

  if (message != NULL)
    {
      argv[argc++] = "--message";
      argv[argc++] = message;
    }

  argv[argc] = NULL;
  
  gnome_client_set_clone_command (client, argc, argv);
  gnome_client_set_restart_command (client, argc, argv);

  return TRUE;
}

static void
session_die (GnomeClient* client, 
             gpointer client_data)
{
  gtk_main_quit ();
}
