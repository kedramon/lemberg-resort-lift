<?php

/**
 * @file
 * Contains lift delete confirm form.
 */

/**
 * Lift delete confirmation form.
 */
function lift_delete_confirm_form($form, &$form_state) {
  $lift = $form_state['lift'];
  return confirm_form(
    $form, t('Are you sure you want to delete lift "%title"', array('%title' => entity_label('lift', $lift))), 'admin/content/lift', t('Activation data and log assigned to this lift will also be deleted. This action cannot be undone.')
  );
}

/**
 * Lift delete confirmation form submit callback.
 */
function lift_delete_confirm_form_submit($form, &$form_state) {
  if ($form_state['values']['confirm']) {
    $lift = $form_state['lift'];

    // Title is not available after deletion.
    $title = entity_label('lift', $lift);
    $return = $lift->delete();
    if ($return !== FALSE) {
      drupal_set_message(t('Lift %title has been deleted.', array('%title' => $title)));

      $form_state['redirect'] = 'admin/content/lifts';
    }
    else {
      drupal_set_message(t('There was an error during deleting lift from the database. If the issue persists, please contact the site administrator'), 'error');
    }
  }
}
