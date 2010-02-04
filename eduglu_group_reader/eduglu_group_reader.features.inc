<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function eduglu_group_reader_ctools_plugin_api() {
  module_load_include('inc', 'eduglu_group_reader', 'eduglu_group_reader.defaults');
  $args = func_get_args();
  return call_user_func_array('_eduglu_group_reader_ctools_plugin_api', $args);
}

/**
 * Implementation of hook_feeds_importer_default().
 */
function eduglu_group_reader_feeds_importer_default() {
  module_load_include('inc', 'eduglu_group_reader', 'eduglu_group_reader.defaults');
  $args = func_get_args();
  return call_user_func_array('_eduglu_group_reader_feeds_importer_default', $args);
}

/**
 * Implementation of hook_menu_default_items().
 */
function eduglu_group_reader_menu_default_items() {
  module_load_include('inc', 'eduglu_group_reader', 'eduglu_group_reader.defaults');
  $args = func_get_args();
  return call_user_func_array('_eduglu_group_reader_menu_default_items', $args);
}

/**
 * Implementation of hook_views_default_views().
 */
function eduglu_group_reader_views_default_views() {
  module_load_include('inc', 'eduglu_group_reader', 'eduglu_group_reader.features.views');
  $args = func_get_args();
  return call_user_func_array('_eduglu_group_reader_views_default_views', $args);
}
