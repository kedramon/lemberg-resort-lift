<?php
/**
 * Lift label callback
 * @param $entity
 * @param $entity_type
 * @return mixed
 */
function lift_entity_label($entity, $entity_type) {
  $wrapper = entity_metadata_wrapper($entity_type, $entity);
  return $wrapper->lift_name->value();
}

/**
 * Lift access callback.
 *
 * @param string $op
 *   Operation being performed. Default to 'view'.
 * @param Lift $lift
 *   Lift entity object.
 * @param stdClass $account
 *   User account performing an operation.
 * @return bool
 *   TRUE if access is allowed, FALSE otherwise.
 */
function lift_access($op = 'view', Lift $lift = NULL, stdClass $account = NULL) {
  switch ($op) {
    case 'view':
      return ($lift->status && user_access('access lifts', $account)) || user_access('manage lifts', $account);
    default:
      return user_access('manage lifts', $account);
  }
}
