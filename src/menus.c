/* menus.c
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

/*** gnomehello-menus */

#include <config.h>
#include "menus.h"
#include "app.h"

static void nothing_cb(GtkWidget* widget, gpointer data);
static void new_app_cb(GtkWidget* widget, gpointer data);
static void close_cb  (GtkWidget* widget, gpointer data);
static void exit_cb   (GtkWidget* widget, gpointer data);
static void about_cb  (GtkWidget* widget, gpointer data);


static GnomeUIInfo file_menu [] = {
  GNOMEUIINFO_MENU_NEW_ITEM(N_("_New Hello"),
                            N_("Create a new hello"),
                            new_app_cb, NULL),

  GNOMEUIINFO_MENU_OPEN_ITEM(nothing_cb, NULL),

  GNOMEUIINFO_MENU_SAVE_ITEM(nothing_cb, NULL),

  GNOMEUIINFO_MENU_SAVE_AS_ITEM(nothing_cb, NULL),

  GNOMEUIINFO_SEPARATOR,

  GNOMEUIINFO_MENU_CLOSE_ITEM(close_cb, NULL),

  GNOMEUIINFO_MENU_EXIT_ITEM(exit_cb, NULL),

  GNOMEUIINFO_END
};

static GnomeUIInfo edit_menu [] = {
  GNOMEUIINFO_MENU_CUT_ITEM(nothing_cb, NULL), 
  GNOMEUIINFO_MENU_COPY_ITEM(nothing_cb, NULL),
  GNOMEUIINFO_MENU_PASTE_ITEM(nothing_cb, NULL),
  GNOMEUIINFO_MENU_SELECT_ALL_ITEM(nothing_cb, NULL), 
  GNOMEUIINFO_MENU_CLEAR_ITEM(nothing_cb, NULL),
  GNOMEUIINFO_MENU_UNDO_ITEM(nothing_cb, NULL),
  GNOMEUIINFO_MENU_REDO_ITEM(nothing_cb, NULL), 
  GNOMEUIINFO_MENU_FIND_ITEM(nothing_cb, NULL), 
  GNOMEUIINFO_MENU_FIND_AGAIN_ITEM(nothing_cb, NULL), 
  GNOMEUIINFO_MENU_REPLACE_ITEM(nothing_cb, NULL),
  GNOMEUIINFO_MENU_PROPERTIES_ITEM(nothing_cb, NULL),
  GNOMEUIINFO_END
};

static GnomeUIInfo help_menu [] = {
  GNOMEUIINFO_HELP ("gnome-hello"),
  
  GNOMEUIINFO_MENU_ABOUT_ITEM(about_cb, NULL),
  
  GNOMEUIINFO_END
};

static GnomeUIInfo menu [] = {
  GNOMEUIINFO_MENU_FILE_TREE(file_menu),
  GNOMEUIINFO_MENU_EDIT_TREE(edit_menu),
  GNOMEUIINFO_MENU_HELP_TREE(help_menu),
  GNOMEUIINFO_END
};

static GnomeUIInfo toolbar [] = {
  GNOMEUIINFO_ITEM_STOCK (N_("New"), N_("Create a new hello"), nothing_cb, GTK_STOCK_NEW),

  GNOMEUIINFO_SEPARATOR,

  GNOMEUIINFO_ITEM_STOCK (N_("Prev"), N_("Previous hello"), nothing_cb, GTK_STOCK_GO_BACK),
  GNOMEUIINFO_ITEM_STOCK (N_("Next"), N_("Next hello"), nothing_cb, GTK_STOCK_GO_FORWARD),

  GNOMEUIINFO_END
};


void 
hello_install_menus_and_toolbar(GtkWidget* app)
{
  gnome_app_create_toolbar_with_data(GNOME_APP(app), toolbar, app);
  gnome_app_create_menus_with_data(GNOME_APP(app), menu, app);
  gnome_app_install_menu_hints(GNOME_APP(app), menu);
}

static void 
nothing_cb(GtkWidget* widget, gpointer data)
{
  GtkWidget* dialog;
  GtkWidget* app;
  
  app = (GtkWidget*) data;

  dialog = gtk_message_dialog_new (GTK_WINDOW (app),
				   GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT,
				   GTK_MESSAGE_INFO,
				   GTK_BUTTONS_OK,
				   _("This does nothing; it is only a demonstration."));

  gtk_dialog_run (GTK_DIALOG (dialog));
  gtk_widget_destroy (dialog);
}

static void 
new_app_cb(GtkWidget* widget, gpointer data)
{
  GtkWidget* app;

  app = hello_app_new(_("Hello, World!"), NULL, NULL);

  gtk_widget_show_all(app);
}

static void 
close_cb(GtkWidget* widget, gpointer data)
{
  GtkWidget* app;

  app = (GtkWidget*) data;

  hello_app_close(app);
}

static void 
exit_cb(GtkWidget* widget, gpointer data)
{
  gtk_main_quit();
}

static void 
about_cb(GtkWidget* widget, gpointer data)
{
  static GtkWidget* dialog = NULL;
  GtkWidget* app;

  app = (GtkWidget*) data;

  if (dialog != NULL) 
    {
      g_assert(GTK_WIDGET_REALIZED(dialog));
      gdk_window_show(dialog->window);
      gdk_window_raise(dialog->window);
    }
  else
    {        
      const gchar *authors[] = {
        "Havoc Pennington <hp@pobox.com>",
        NULL
      };
     GdkPixbuf* logo;
     gchar* logo_filename = NULL;

     logo_filename = g_strdup(DATADIR "/pixmaps/gnome-hello-logo.png");

     logo = gdk_pixbuf_new_from_file(logo_filename, NULL); 
     dialog = gnome_about_new (_("GNOME Hello"), 
				VERSION,
                                "(C) 1999 Havoc Pennington",
                                _("A sample GNOME application."),
                                authors,
				NULL,
				NULL,
                                logo);

      gtk_window_set_transient_for (GTK_WINDOW (dialog), GTK_WINDOW (app));	
      if (logo)
	gdk_pixbuf_unref (logo);
      g_free(logo_filename);

      g_signal_connect(G_OBJECT(dialog),
                         "destroy",
                         G_CALLBACK(gtk_widget_destroyed),
                         &dialog); 

      gtk_widget_show(dialog);
    }
}


/* gnomehello-menus ***/
