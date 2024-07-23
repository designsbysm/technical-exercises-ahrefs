type response;

module Response = {
  type t = response;

  [@mel.send.pipe: t] external json: Js.Promise.t(Js.Json.t) = "json";
};

external fetch: string => Js.Promise.t(response) = "fetch";
