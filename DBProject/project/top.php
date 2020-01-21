<H1>Физтабло 1.0</H1>
<p class="login">
    <?php
     $fileWithName = fopen('pages/loginPage/name.txt', 'r');
     $userName = fgets($fileWithName);
     if (empty($userName)) { ?>
         Преподавтатель? <a href="pages/loginPage/loginPage.php">Войти</a>
         <?
     }
     else
     {
         echo "Добро пожаловать, <br/> $userName | "; ?>
    <a href="pages/lk/lk.php">Личный кабинет</a>
    <?
     }
    ?>
</p>