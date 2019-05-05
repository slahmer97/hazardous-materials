const path = require('path');
const MiniCssExtractPlugin = require("mini-css-extract-plugin");

module.exports = {
	mode: "development",
	entry: "./src/index.ls",
	output: {
		filename: "main.js",
		path: path.resolve(__dirname, "dist")
	},
	node: {
		fs: "empty"
	},
	module: {
		rules: [
			{
				test: /\.ls$/,
				use: [
					{loader: 'livescript-loader'}
				]
			},
			{
				test: /\.sass$/,
				use: [
					{
						loader: MiniCssExtractPlugin.loader,
						options: {
							publicPath: '../'
						}
					},
					"css-loader",
					"sass-loader"
				],
			}
		]
	},
	plugins: [
        new MiniCssExtractPlugin({
            filename: "[name].css",
            chunkFilename: "[id].css"
        })
	]
};
