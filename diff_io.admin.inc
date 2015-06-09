<?php

function diff_io_admin_settings() {

  // figure out an example and valid request
  $example_url = variable_get('diff_io_example_url', 'http://drupal.org');
  if( empty( $example_url ) ){
    $example_url = 'http://drupal.org';
  }
  $diff_io_job = diff_io_url( $example_url );

  // create a link to that url
  $diff_io_job_link = l( t('diff.io request to establish'), $diff_io_job, array('attributes' => array('target'=>'_blank') ) );

  // get the number of jobs run today
  $calls_this_month = (int) variable_get('diff_io_monthly_calls:'. date("Y-m"), '0');

  // get the maximum allowed montly jobs
  $diff_io_monthly_max = (int) variable_get('diff_io_monthly_max', '100');

  // form items below this line
  $form['diff_io_signup'] = array(
    '#type' => 'item',
    '#title' => l('Visit diff.io for more details about account types', 'https://diff.io', array('attributes' => array('target'=>'_blank') ) )
  );

  $form['diff_io_api_key'] = array(
    '#type' => 'textfield',
    '#title' => 'api key',
    '#description' => 'This key was sent to you upon signup, and begins with a capital "P".',
    '#default_value' => variable_get('diff_io_api_key', ''),
  );

  $form['diff_io_secret_key'] = array(
    '#type' => 'textfield',
    '#title' => 'api secret',
    '#description' => 'This key was sent to you upon signup, and begins with a capital "S".',
    '#default_value' => variable_get('diff_io_secret_key', ''),
  );

  $form['diff_io_host'] = array(
    '#type' => 'textfield',
    '#title' => 'api end point',
    '#description' => 'Should be https://api.diff.io/v1/diff/ by default.',
    '#default_value' => variable_get('diff_io_host', 'https://api.diff.io/v1/diff/'),
  );

  $form['diff_io_monthly_max'] = array(
    '#type' => 'textfield',
    '#title' => 'Monthly request limit',
    '#description' => 'Maximum requests to allow per month: via just this site: via diff_io_call(). Currently at ' . $calls_this_month . '/' . $diff_io_monthly_max,
    '#element_validate' => array('element_validate_integer_positive'),
    '#default_value' => $diff_io_monthly_max,
  );

  $form['diff_io_example_url'] = array(
    '#type' => 'textfield',
    '#title' => 'Trigger a ' . $diff_io_job_link . " your account and configuration are functional.",
    '#default_value' => $example_url,
    '#description' => 'Save, then click the link above to confirm a functional configuration.',
  );

  return system_settings_form($form);
}

function diff_io_setting_validate($form, $form_state){
    $config_date_expiration = $form_state['values']['limit']['config_date_expiration'];

    die('test');
    // if (!is_numeric($config_date_expiration)) {
    //     form_set_error('config_date_expiration', t('You must enter an integer for the date expiration of point.'));
    // }
    // elseif ($config_date_expiration <= 0) {
    //     form_set_error('config_date_expiration', t('The date expiration of point must be positive.'));
    // }
}