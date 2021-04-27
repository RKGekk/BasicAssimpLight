#pragma once

#include <DirectXMath.h>

struct CB_VS_VertexShader {
	DirectX::XMFLOAT4X4 lwvpMatrix;
	DirectX::XMFLOAT4X4 invWorldMatrix;
	DirectX::XMFLOAT4X4 worldMatrix;
};

struct CB_PS_PixelShader_Light {
	DirectX::XMFLOAT3 color;
	float ambientLightStrength;

	DirectX::XMFLOAT3 dColor;
	float dLightStrength;

	DirectX::XMFLOAT3 dPos;
	float dAtt_a;
	float dAtt_b;
	float dAtt_c;
};