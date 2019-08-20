# docker_build_env_for_cpp
A template repo for build of c++ project in docker image


#instruction
#build docker</b>
docker build -t example_cpp_build .
#run docker<b/>
docker run -v $PWD:/opt/build example_cpp_build



