<?php
/**
 * @file
 * Admin form(s) to manage module settings
 *
 */

/**
 * 
 * Administration form for module settings
 *
 */
function anti_bot_settings() {
  $config          = config('anti_bot.settings');
  $protected_forms = $config->get('protected_forms');
  $forms_list      = implode("\n", $protected_forms);
  $form            = array();

  $form['anti_bot_forms'] = array(
    '#type' => 'textarea',
    '#title' => "Form ID's",
    '#description' => t("List of form id's that are should be protected by module, one form_id per line."),
    '#default_value' => $forms_list,
  );
  $form['anti_bot_log'] = array(
    '#type' => 'checkbox',
    '#title' => t('Log blocked form submissions'),
    '#default_value' => $config->get('log_blocked'),
  );
  $form['actions'] = array(
    '#type' => 'actions',
  );
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save configuration'),
  );
  
  return $form;
}

/**
 * Implements hook_submit().
 * 
 */
function anti_bot_settings_submit($form, &$form_state) {
  
  $config         = config('anti_bot.settings');
  $anti_bot_forms = trim($form_state['values']['anti_bot_forms']);
  
  if (!empty($anti_bot_forms)) {
    $raw_array = preg_split("/\\r\\n|\\r|\\n/", $anti_bot_forms);
    $protected_forms = array_map('trim', $raw_array);
  }
  else {
    $protected_forms = array();
  }
  
  $config->set('protected_forms', $protected_forms);
  $config->set('log_blocked',     $form_state['values']['anti_bot_log']);
  $config->save();
  
  backdrop_set_message(t('The configuration options have been saved.'));
}

