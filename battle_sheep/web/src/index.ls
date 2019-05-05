maquette = require "maquette"

require "./style.sass"

h = maquette.h
projector = maquette.createProjector!

socket = new WebSocket "ws://localhost:3000/"

model = {
	card: "resources/island.jpg"
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
					h 'input.hello', {
						type: "submit"
						value: "Hello there!"
						onclick: (e) ->
							alert "General Kenobi"
					}
					h 'input.input', {
						type: "text"
						oninput: (e) ->
							model.login = e.target.value
					}
					h 'input.input', {
						type: "password"
						oninput: (e) ->
							model.password = e.target.value
					}
					h 'input.button.is-fullwidth', {
						type: "submit"
						value: "Sign in"
						onclick: (e) ->
							socket.send JSON.stringify {
								type: "login"
								login: model.login
								password: model.password
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
					h 'input.input', {
						type: "text"
						oninput: (e) ->
							model.login = e.target.value
						}

						h 'input.input', {
							type: "password"
							oninput: (e) ->
								model.password = e.target.value
						}
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
					h 'div.grid1', [
						for x in [0 to 9]
							for y in [0 to 9]
								h "div.tile", {
									key: '1:' + x + ':' + y
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

					h 'div.grid2', [
						for x in [0 to 9]
							for y in [0 to 9]
								h "div.tile", {
									key: '2:' + x + ':' + y
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
