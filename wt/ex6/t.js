var myApp=angular.module("myApp",[]);

myApp.controller("firstController",function ($scope,$interval) {
  


    $scope.test=function(){
        $interval(function(){
            $scope.time=new Date().toLocaleTimeString();
        },1000);

    };
});

