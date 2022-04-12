<?php
    session_start();
    require_once 'config.php';

    if (isset($_POST['email']) AND isset($_POST['password']))
    {
        $email = htmlspecialchars($_POST['email']);
        $password = htmlspecialchars($_POST['paswword']);

        $check = $bdd->prepare('SELECT pseudo, email, password FROM esthetea and estheteb WHERE email=?');
        $check->execute(array($email));
        $data = $check->fetch();
        $row = $check->rowCount();

        if ($row==1)
        {
            if(filter_var($email, FILTER_VALIDATE_EMAIL))
            {

                if($data['password']=== $password)
                {

                    $_SESSION['user'] = $data['pseudo'];
                    header('Location:connection.php');

                }else header ('Location:connection.php?login_err=password');
            }else header('Location:connection.php?login_err=email');
        }else header('Location:connection.php?login_err=already');

    }else{
        header('Location:connection.php');
    }