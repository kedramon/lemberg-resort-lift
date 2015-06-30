<?php

/**
 * @file
 * Contains lift entity form.
 */

/**
 * Lift entity edit form.
 */
function lift_edit_form($form, &$form_state) {
  $lift = $form_state['lift'];

  $form['options'] = array(
    '#type' => 'fieldset',
    '#title' => t('Publishing options'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#group' => 'additional_settings',
    '#weight' => 95,
  );
  $form['options']['status'] = array(
    '#type' => 'checkbox',
    '#title' => t('Published'),
    '#default_value' => $lift->status,
  );

  $form['actions'] = array(
    '#type' => 'actions',
  );
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );

  field_attach_form('lift', $lift, $form, $form_state);

  return $form;
}

/**
 * Lift entity edit form validation callback.
 */
function lift_edit_form_validate($form, &$form_state) {
  entity_form_field_validate('lift', $form, $form_state);
}

/**
 * Lift entity edit form submit callback.
 */
function lift_edit_form_submit($form, &$form_state) {
  $lift = $form_state['lift'];
  form_state_values_clean($form_state);
  entity_form_submit_build_entity('lift', $lift, $form, $form_state);

  $return = $lift->save();
  if ($return) {
    if ($return == SAVED_NEW) {
      drupal_set_message(t('Lift %title has been created.', array('%title' => entity_label('lift', $lift))));
    }
    else {
      drupal_set_message(t('Lift %title has been updated.', array('%title' => entity_label('lift', $lift))));
    }
    $form_state['redirect'] = 'admin/content/lifts';
  }
  else {
    drupal_set_message(t('There was an error during saving Lift to the database. If the issue persists, please contact the site administrator'), 'error');
  }
}
