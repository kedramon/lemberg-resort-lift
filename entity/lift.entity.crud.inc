<?php

/* Lift entity CRUD fucntions */

// Create lift entity
function lift_create(array $values = array()) {
  return new Lift($values);
}

// Save lift entity
function lift_save(Lift $lift) {
  return entity_save('lift', $lift);
}

// Load lift entity
function lift_load($lid) {
  $result = entity_load('lift', array($lid));
  return $result ? reset($result) : FALSE;
}

// Load multiple lift entities
function lift_load_multiple($lids = array(), $conditions = array()) {
  return entity_load('lift', $lids, $conditions);
}

// Delete lift entity
function lift_delete($lid) {
  return lift_delete_multiple(array($lid));
}

// Delete many lift entities
function lift_delete_multiple($lids) {
  return entity_delete_multiple('lifts', $lids);
}
