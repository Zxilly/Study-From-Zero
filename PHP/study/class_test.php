<?php

class page
{
    var $url;
    var $title;

    function geturl($get)
    {
        $this->url = $get;
    }

    function gettitle($get)
    {
        $this->title = $get;
    }

    function puturl()
    {
        echo $this->url . PHP_EOL;
    }

    function puttitle()
    {
        echo $this->title . PHP_EOL;
    }
}

