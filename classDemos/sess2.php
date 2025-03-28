<?php
session_start();
?>
<html>

<head>
  <title>Session Stuff 2</title>
</head>

<body>
  <?php
// REtrieve session variables
echo 'Favorite color is ' . $_SESSION['favcolor'] . '.<br>';
echo 'Favorte animal is ' . $_SESSION['favanimal'] . '.<br><br>';
echo '<br><br><pre>' . print_r($_SESSION) . '</pre>';
// Change Favorite Color
$_SESSION['favcolor'] = 'yellow';
echo '<br><br><pre>';
print_r($_SESSION);
echo '</pre>';
// Change fav color
$_SESSION['list'] = array(3, 2, 1, -17);
echo '<br><br><pre>';
echo print_r($_SESSION);
echo '</pre>';
?>
</body>

</html>
