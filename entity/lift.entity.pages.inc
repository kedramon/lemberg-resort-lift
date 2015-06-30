<?php

/**
 * @file
 * Lift entity pages.
 */

/**
 * Menu callback. Returns lift add/edit form.
 */
function lift_add_page(Lift $lift = NULL) {
  $lift = !empty($lift) ? $lift : lift_create();

  $title = empty($lift->lid) ? t('Add new lift') : t('Edit lift %title', array('%title' => entity_label('lift', $lift)));
  drupal_set_title($title, PASS_THROUGH);

  module_load_include('inc', 'lift', 'forms/lift.entity_form');
  $form_state = array(
    'lift' => $lift,
  );
  return drupal_build_form('lift_edit_form', $form_state);
}

/**
 * Menu callback. Returns lift delete confirmation form.
 */
function lift_delete_page(Lift $lift) {
  module_load_include('inc', 'lift', 'forms/lift.delete_confirm_form');
  $form_state = array(
    'lift' => $lift,
  );
  return drupal_build_form('lift_delete_confirm_form', $form_state);
}

/**
 * Menu callback. Returns lift view page.
 */
function lift_view_page(Lift $lift, $view_mode = 'landing') {
  if ($view_mode === 'output') {
    $entity_uri = entity_uri('lift', $lift);
    drupal_goto($entity_uri['path']);
  }

  return $lift->view($view_mode, NULL, TRUE);
}
