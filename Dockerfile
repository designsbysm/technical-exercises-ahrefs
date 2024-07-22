FROM ocaml/opam:ubuntu-lts-ocaml-4.12

USER root
RUN apt-get update --fix-missing
RUN apt-get upgrade -y
RUN apt-get install -y npm
RUN npm install -g http-server

WORKDIR /app
ENV PATH _opam/bin:$PATH
COPY . .

RUN npm install
RUN opam switch create . 5.1.1 -y --deps-only
RUN opam install -y . --deps-only --with-test
RUN dune build

CMD http-server dist
