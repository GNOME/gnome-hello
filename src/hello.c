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

#include "config.h"

#include <glib-object.h>
#include <glib/gi18n.h>

#include "app.h"


static gboolean greet_mode = FALSE;
static char *message  = NULL;
static char *geometry = NULL;
static char **args = NULL;

static GOptionEntry option_entries[] =
{
  {
    "greet",
    'g',
    0,
    G_OPTION_ARG_NONE,
    &greet_mode,
    N_("Say hello to specific people listed on the command line"),
    NULL
  },
  { 
    "message",
    'm',
    0,
    G_OPTION_ARG_STRING,
    &message,
    N_("Specify a message other than \"Hello, World!\""),
    N_("MESSAGE")
  },
  { 
    "geometry",
    0,
    0,
    G_OPTION_ARG_STRING,
    &geometry,
    N_("Specify the geometry of the main window"),
    N_("GEOMETRY")
  },
  { 
    G_OPTION_REMAINING,
    0,
    0,
    G_OPTION_ARG_STRING_ARRAY,
    &args,
    NULL,
    NULL
  },
  {
    NULL
  }
};

int 
main (int argc, char **argv)
{
  GtkWidget *app;
  GError *error = NULL;
  GSList *greet = NULL;
  int i;

  bindtextdomain (GETTEXT_PACKAGE, GNOMELOCALEDIR);  
  bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");
  textdomain (GETTEXT_PACKAGE);

  /* Initialize GTK+ program */
  if (!gtk_init_with_args (&argc, &argv,
                           _("- GNOME Hello"),
                           option_entries,
                           GETTEXT_PACKAGE,
                           &error))
    {
      g_printerr (_("%s\nRun '%s --help' to see a full list of available command line options.\n"),
                  error->message, argv[0]);
      g_error_free (error);
      return 1;
    }

  /* Set default window icon */
  gtk_window_set_default_icon_name ("gnome-hello-logo");

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

  app = hello_app_new (message, geometry, greet);

  g_slist_free (greet);

  gtk_widget_show_all(app);

  gtk_main ();

  return 0;
}
