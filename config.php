<?php
    try
    {
        $bdd = new PDO('mysql:host=localhost;dbname=esthete;charset=UTF8', 'root', '');
    }catch(Exception $e)
    {
        die('erreur'. $e->getMessage());
    }
