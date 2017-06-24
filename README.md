Anti bot
========

Prevents form submissions by spambots.
Module adds for protected forms two checkboxes with randomly generated names: 
one visible as "I'm not a robot" and one visually hidden "I'm a spambot".

Installation
------------
Install this module using the official Backdrop CMS instructions at 
https://backdropcms.org/guide/modules

Configuration and usage
-----------------------
Administration page is available via menu *Administration > Configuration > 
User accounts > Anti bot* (admin/config/people/anti-bot) 
and may be used for add/remove forms IDs, which should be protected.

Please note: when you install module, comments form for all existing content types (in other words - node types)
will be added automatically, same as site-wide contact form (if "Contact" module is enabled).  


License
-------
This project is GPL v2 software. See the LICENSE.txt file in this directory for
complete text.

Credits
-------
Inspired by Drupal 7 module "Simple Anti-Spam" (https://www.drupal.org/project/simpleantispam) 

Current Maintainer
------------------
Vladimir (https://github.com/findlabnet/)

More information
----------------
For bug reports, feature or support requests, please use the module 
issue queue at https://github.com/findlabnet/anti_bot/issues
 
