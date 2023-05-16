#!/usr/bin/env bash

# Set up authentication:
# API Key: IDUBRt2cJoITeBKl9rAD1eCBaDYI0XBYKwQ7jrLWpnEceFBEPnS0gF804T2pSQ02
# Secret Key: bjEUGuMp745yDARPXe6tZ2WnMzL36okqAGMiIIbzHNbirFU2O4oQ6EQjjqBQaqTb
API_KEY="IDUBRt2cJoITeBKl9rAD1eCBaDYI0XBYKwQ7jrLWpnEceFBEPnS0gF804T2pSQ02"
PRIVATE_KEY_PATH="test-prv-key.pem"

# Set up the request:
API_METHOD="POST"
API_CALL="api/v3/order"
API_PARAMS="symbol=BTCUSDT&side=SELL&type=LIMIT&timeInForce=GTC&quantity=1&price=0.2"

# Sign the request:
timestamp=$(date +%s000)
api_params_with_timestamp="$API_PARAMS&timestamp=$timestamp"
signature=$(echo -n "$api_params_with_timestamp" \
            | openssl dgst -sha256 -sign "$PRIVATE_KEY_PATH" \
            | openssl enc -base64 -A)

# Send the request:
curl -H "X-MBX-APIKEY: $API_KEY" -X "$API_METHOD" \
    "https://testnet.binance.vision/$API_CALL?$api_params_with_timestamp" \
    --data-urlencode "signature=$signature"