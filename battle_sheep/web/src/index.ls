maquette = require "maquette"

require "./style.sass"

h = maquette.h
projector = maquette.createProjector!

socket = new WebSocket "wss://localhost:8080/game"

model = {
	state: "login"

	login: ""
	password: ""

	menu: ": Page d'accueil"
	loginMenu: ": Page d'accueil"
	registerMenu: ": Enregistrement"
	gameMenu: ": Ecran de jeu"
}

socket.onmessage = (event) ->
	message = JSON.parse event.data
	console.log "Message received => #{message.data}"

	switch message.type
	| "card"
		model.card = "resources/#{message.data}.png"
	| "loginsuccess"
		model.state = "index"
		model.menu = model.gameMenu

	projector.scheduleRender!

hello = ->
	h 'input.hello', {
		type: "submit"
		value: "Hello there!"
		onclick: (e) ->
			alert "General Kenobi..."
	}

logincomponent = (n) ->
	str = ""
	if n == 1
		str = "Entrez votre identifiant"
	else
		str = "Choisissez un identifiant"

	h 'div.loginarea', [
		str
		h 'input.input', {
			type: "text"
			oninput: (e) ->
				model.login = e.target.value
		}
	]

passwordcomponent = (n) ->
	str = ""
	if n == 1
		str = "Entrez votre mot de passe"
	else
		str = "Choisissez un mot de passe"

	h 'div.passwordarea', [
		"Entrez votre mot de passe"
		h 'input.input', {
			type: "password"
			oninput: (e) ->
				model.password = e.target.value
		}
	]

grid = (n) ->
	h "div.grid#{n}", [
	for x in [0 to 9]
		for y in [0 to 9]
			h "div.tile", {
				key: "#{n}:#{x}:#{y}"
				style: """
					display: inline-block;
					position: absolute;
					left: #{32*y}px;
					top: #{32*x}px;
					width: 32px;
					height: 32px;
				"""
			}
	]

render = ->
	h 'div.section', [
		h 'div.gamename', {
			key: "gamename"
		}, [ "Bataille aéronavale#{model.menu}"
		]
		h 'div.container', [
			switch model.state
			| "login" =>
				model.menu = model.loginMenu

				h 'div.form', {
					key: "login"
				}, [
					hello!
					logincomponent 1
					passwordcomponent 1
					h 'input.button.is-fullwidth', {
						type: "submit"
						value: "Sign in"
						onclick: (e) ->
							model.state = "index"
							model.menu = model.gameMenu

							socket.send JSON.stringify {
								msg_type: "login"
								login: "#{model.login},#{model.password}"
								#password: model.password
							}
					}, ["Send"]
					h 'input.button.is-fullwidth', {
						type: "submit"
						value: "Register"
						onclick: (e) ->
							model.state = "register"
							model.menu = model.registerMenu
							projector.scheduleRender!
					}, ["Register"]
				]
			| "register" =>
				h 'div.form', {
					key: "register"
				}, [
					logincomponent 2
					passwordcomponent 2

					h 'input.button', {
						type: "submit"
						value: "Sign up"
						onclick: (e) ->
							socket.send JSON.stringify {
								type: "register"
								login: model.login
								password: model.password
							}
					}, ["Send"]
					h 'input.button', {
						value: "Go back"
						onclick: (e) ->
							model.state = 'login'
							model.menu = model.loginMenu
							projector.scheduleRender!
						}
				]
			| "index" =>
				model.menu = ": Ecran de jeu"
				h 'div.container', {
					key: "maindiv"
				}, [
					h 'div.enemygrids', [
						grid 1
						grid 2
					]
					h 'div.allygrids', [
						grid 3
						grid 4
					]
					h 'input.button', {
						value: 'Disconnect'
						onclick: (e) ->
							model.login = ""
							model.password = ""
							model.state = "login"
							model.menu = model.loginMenu
							projector.scheduleRender!
					}
				]
		]
	]
document.addEventListener 'DOMContentLoaded', ->
	projector.append document.body, render
