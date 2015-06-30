<?php

/**
 * @file
 * Provides custom Lift entity class.
 */

/**
 * Lift entity.
 */
class Lift extends Entity {

  /**
   * Lift primary ID.
   *
   * @var int
   */
  public $lid;

  /**
   * Lift record creation Unix timestamp.
   *
   * @var int
   */
  public $created = REQUEST_TIME;

  /**
   * Lift record most recent update Unix timestamp.
   *
   * @var int
   */
  public $changed = REQUEST_TIME;

  /**
   * Lift publishing status.
   *
   * @var bool
   */
  public $status = TRUE;

  /**
   * Lift a new Lift record entity.
   *
   * @see entity_create()
   */
  public function __construct(array $values = array()) {
    parent::__construct($values, 'lift');
  }
}
