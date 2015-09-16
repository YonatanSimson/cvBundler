/* 
 *  Copyright (c) 2008-2010  Noah Snavely (snavely (at) cs.cornell.edu)
 *    and the University of Washington
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 */

/* BundlerAppMain.cpp */

#include "BundlerApp.h"


static BundlerApp *bundler_app = NULL;

BundlerApp &wxGetApp() {
    return *bundler_app;
}

int main(int argc, char **argv) 
{
    // mtrace();

    bundler_app = new BundlerApp();
    bundler_app->argc = argc;
    bundler_app->argv = argv;

    bundler_app->OnInit();
}
