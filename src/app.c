/* app.c
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

/*** gnomehello-app */

#include <config.h>
#include "app.h"
#include "menus.h"

/* Keep a list of all open application windows */
static GSList* app_list = NULL;

static gint delete_event_cb(GtkWidget* w, GdkEventAny* e, gpointer data);
static void button_click_cb(GtkWidget* w, gpointer data);

GtkWidget* 
hello_app_new(const gchar* message, 
              const gchar* geometry,
              GSList* greet)
{
  GtkWidget* app;
  GtkWidget* button;
  GtkWidget* label;
  GtkWidget* status;
  GtkWidget* frame;

  /*** gnomehello-widgets */
  app = gnome_app_new(PACKAGE, _("Gnome Hello"));

  frame = gtk_frame_new(NULL);

  button = gtk_button_new();

  label  = gtk_label_new(message ? message : _("Hello, World!"));

  gtk_window_set_policy(GTK_WINDOW(app), FALSE, TRUE, FALSE);
  gtk_window_set_default_size(GTK_WINDOW(app), 250, 350);
  gtk_window_set_wmclass(GTK_WINDOW(app), "hello", "GnomeHello");

  gtk_frame_set_shadow_type(GTK_FRAME(frame), GTK_SHADOW_IN);

  gtk_container_set_border_width(GTK_CONTAINER(button), 10);

  gtk_container_add(GTK_CONTAINER(button), label);

  gtk_container_add(GTK_CONTAINER(frame), button);

  gnome_app_set_contents(GNOME_APP(app), frame);

  status = gnome_appbar_new(FALSE, TRUE, GNOME_PREFERENCES_NEVER);

  gnome_app_set_statusbar(GNOME_APP(app), status);

  hello_install_menus_and_toolbar(app);

  /* gnomehello-widgets ***/
  
  /*** gnomehello-signals */
  g_signal_connect(G_OBJECT(app),
                   "delete_event",
                   G_CALLBACK(delete_event_cb),
                   NULL);

  g_signal_connect(G_OBJECT(button),
                   "clicked",
                   G_CALLBACK(button_click_cb),
                   label);
  /* gnomehello-signals ***/

  /* gnomehello-geometry ***/
  if (geometry != NULL) 
    {
      if (!gtk_window_parse_geometry (GTK_WINDOW(app), geometry)) 
        {
          g_error(_("Could not parse geometry string `%s'"), geometry);
        }
    }

  /* gnomehello-geometry ***/

  if (greet != NULL)
    {
      GtkWidget* dialog;
      gchar* greetings = g_strdup(_("Special Greetings to:\n"));
      GSList* tmp = greet;

      while (tmp != NULL)
        {
          gchar* old = greetings;

          greetings = g_strconcat(old, 
                                  (gchar*) tmp->data,
                                  "\n",
                                  NULL);
          g_free(old);

          tmp = g_slist_next(tmp);
        }
      
      dialog = gtk_message_dialog_new (GTK_WINDOW (app),
				       GTK_DIALOG_DESTROY_WITH_PARENT,
				       GTK_MESSAGE_INFO,
				       GTK_BUTTONS_OK,
				       greetings,
				       NULL);
      g_signal_connect (dialog, "response",
			G_CALLBACK (gtk_object_destroy), NULL);
      gtk_widget_show (dialog);

      g_free(greetings);

    }

  app_list = g_slist_prepend(app_list, app);

  return app;
}

void       
hello_app_close(GtkWidget* app)
{
  g_return_if_fail(GNOME_IS_APP(app));

  app_list = g_slist_remove(app_list, app);

  gtk_widget_destroy(app);

  if (app_list == NULL)
    {
      /* No windows remaining */
      gtk_main_quit();
    }
}

/*** gnomehello-quit */
static gint 
delete_event_cb(GtkWidget* window, GdkEventAny* e, gpointer data)
{
  hello_app_close(window);

  /* Prevent the window's destruction, since we destroyed it 
   * ourselves with hello_app_close()
   */
  return TRUE;
}
/* gnomehello-quit ***/

static void 
button_click_cb(GtkWidget* w, gpointer data)
{
  GtkWidget* label;
  gchar* text;
  gchar* tmp;

  label = GTK_WIDGET(data);

  gtk_label_get(GTK_LABEL(label), &text);

  tmp = g_strdup(text);

  g_strreverse(tmp);

  gtk_label_set_text(GTK_LABEL(label), tmp);

  g_free(tmp);
}

/* gnomehello-app ***/
