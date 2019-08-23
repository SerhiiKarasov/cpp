#Template repo for build of c++ project in docker image  
##Preconfiguration for docker:
https://docs.docker.com/install/linux/linux-postinstall/    

#Instruction  
##build docker image:  
```
docker build --network=host -t example_build .  
```
##run docker container:  
```
docker run --user $(id -u):$(id -g) -v $PWD:/opt/build example_build  
```


