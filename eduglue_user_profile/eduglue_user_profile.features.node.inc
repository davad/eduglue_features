<?php

/**
 * Helper to implementation of hook_node_info().
 */
function _eduglue_user_profile_node_info() {
  $items = array(
    'uprofile' => array(
      'name' => t('User Profile'),
      'module' => 'features',
      'description' => t('Holds the data for a user\'s profile. Needs to be attached to the user via Bio or Nodeprofile.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '0',
      'body_label' => t(''),
    ),
  );
  return $items;
}