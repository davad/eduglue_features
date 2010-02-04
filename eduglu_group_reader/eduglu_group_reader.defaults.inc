<?php

/**
 * Helper to implementation of hook_ctools_plugin_api().
 */
function _eduglu_group_reader_ctools_plugin_api() {
  $args = func_get_args();
  $module = array_shift($args);
  $api = array_shift($args);
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => 1);
  }
}

/**
 * Helper to implementation of hook_feeds_importer_default().
 */
function _eduglu_group_reader_feeds_importer_default() {
  $export = array();
  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'feed';
  $feeds_importer->config = array(
    'name' => 'Feed',
    'description' => 'Import RSS or Atom feeds, create nodes from feed items.',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsSyndicationParser',
      'config' => array(),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'content_type' => 'feed_item',
        'update_existing' => 0,
        'expire' => '-1',
        'mappings' => array(
          '0' => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => FALSE,
          ),
          '1' => array(
            'source' => 'description',
            'target' => 'body',
            'unique' => FALSE,
          ),
          '2' => array(
            'source' => 'timestamp',
            'target' => 'created',
            'unique' => FALSE,
          ),
          '3' => array(
            'source' => 'url',
            'target' => 'url',
            'unique' => TRUE,
          ),
          '4' => array(
            'source' => 'guid',
            'target' => 'guid',
            'unique' => TRUE,
          ),
        ),
      ),
    ),
    'content_type' => 'feed',
    'update' => 0,
    'import_period' => '1800',
    'expire_period' => 3600,
    'import_on_create' => 1,
  );

  $export['feed'] = $feeds_importer;
  return $export;
}

/**
 * Helper to implementation of hook_menu_default_items().
 */
function _eduglu_group_reader_menu_default_items() {
  $items = array();

  $items[] = array(
    'title' => 'Reader',
    'path' => 'group-reader',
    'weight' => '0',
    'description' => 'View and add feeds in a group',
  );
  // Translatables
  array(
    t('Reader'),
    t('View and add feeds in a group'),
  );


  return $items;
}
