<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <link rel="stylesheet" href="inscriptionA.css">
</head>
<body>
    <div class="b1">
        <div class="b11">
        <h1>ESTHETE</h1>
        </div>
    </div>
    <div class="b13">
        <?php 
                if(isset($_GET['reg_err']))
                {
                    $err = htmlspecialchars($_GET['reg_err']);

                    switch($err)
                    {
                        case 'success':
                        ?>
                            <div class="alert alert-success">
                                <strong>Succès</strong> inscription réussie !
                            </div>
                        <?php
                        break;

                        case 'password':
                        ?>
                            <div class="alert alert-danger">
                                <strong>Erreur</strong> mot de passe différent
                            </div>
                        <?php
                        break;

                        case 'email':
                        ?>
                            <div class="alert alert-danger">
                                <strong>Erreur</strong> email non valide
                            </div>
                        <?php
                        break;

                        case 'email_length':
                        ?>
                            <div class="alert alert-danger">
                                <strong>Erreur</strong> email trop long
                            </div>
                        <?php 
                        break;

                        case 'pseudo_length':
                        ?>
                            <div class="alert alert-danger">
                                <strong>Erreur</strong> pseudo trop long
                            </div>
                        <?php 
                        case 'already':
                        ?>
                            <div class="alert alert-danger">
                                <strong>Erreur</strong> compte deja existant
                            </div>
                        <?php 

                    }
                }
                ?>
        <div class="b12"></div>
        <form action="data.php" method="post">
            <h2>M'inscrire</h2>
            <div class="form-group">
                <input type="text" name="pseudo" class="t1" placeholder="Pseudo" required="required" autocomplete="off">
            </div>
            <div class="form-group">
                <input type="email" name="email" class="t2" placeholder="Email" required="required" autocomplete="off">
            </div>
            <div class="form-group">
                <input type="password" name="password" class="t3" placeholder="password" required="required" autocomplete="off">
            </div>
            <div class="form-group">
                <input type="password" name="password_retype" class="t4" placeholder="password" required="required" autocomplete="off">
            </div>
            <button type="submit" class="v1">Connexion</button>
        </form>
    <a href="index.html">
        <div class="b14">
            <h5>Accueil</h5>
        </div>
    </a>
    </div>
</body>
</html>