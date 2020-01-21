<?php
  $fileWithName = fopen('../loginPage/name.txt', 'w');
  //fwrite($fileWithName, ' ');
  fclose($fileWithName);
  header("Location: ..\..\index.php");
/**
 * Created by PhpStorm.
 * User: superuser
 * Date: 31.12.2019
 * Time: 22:24
 */