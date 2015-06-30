<?php

/**
 * @file
 * Lift admin pages.
 */

/**
 * Menu callback. Provides lift admin page.
 */
function lift_admin_page() {
  return array(
    '#markup' => t("Lifts don't have any configuration. This page exists only for Field UI."),
  );
}