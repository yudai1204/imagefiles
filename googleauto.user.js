// ==UserScript==
// @name         Google認証スキップ
// @namespace    @yudai1204
// @version      0.1
// @description  テスト
// @author       うだい
// @match        https://accounts.google.com/*
// @icon         https://www.google.com/favicon.ico
// @grant        none
// ==/UserScript==

(function() {
    'use strict';

    if(location.href.includes("&authuser=")){
        const authorNum = location.href.slice(location.href.indexOf("&authuser=")+10,location.href.indexOf("&authuser=")+11);
        let clicked = false;
        let password="password";
        switch(Number(authorNum)){
            case 0:
                password="";
                break;
            case 1:
                password="";
                break;
            default:
                password="";
                break;
        }
        console.log(authorNum);
        //ログインボタン押す
        if(location.href.slice(0,45).includes("ServiceLogin")){
            console.log("ServiceLogin");
            function clickNextBtn(){
                console.log("loading");
                const nextBtn = document.querySelector("button");
                if(nextBtn){
                    nextBtn.click();
                    console.log("clicked");
                }
            }
            setTimeout(clickNextBtn,200);
            setInterval(inputPassword,300);
        }else if(location.href.includes("v2/challenge")){
            setInterval(inputPassword,300);
        }
        //パスワード入力する
        function inputPassword(){
            if(clicked){
                return;
            }else{
            const passwordBox = document.getElementById("password").querySelector("input");
                if(passwordBox){
                    console.log("passwordBox found!")
                    passwordBox.value = password;
                    const nextPassBtn = document.querySelector("button.nCP5yc");
                    if(nextPassBtn){
                        nextPassBtn.click();
                        clicked = true;
                    }
                }
                else{
                    console.log("passwordBox NotFound");
                }
            }
        }
    }
})();
