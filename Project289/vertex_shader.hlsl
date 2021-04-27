cbuffer perObjectBuffer : register(b0) {
	float4x4 lwvpMatrix;
	float4x4 invWorldMatrix;
	float4x4 worldMatrix;
};

struct VS_INPUT {
	float3 pos : POSITION;
	float3 color : COLOR;
	float2 uv : TEXCOORD;
	float3 normal : NORMAL;
};

struct VS_OUTPUT {
	float4 pos : SV_POSITION;
	float3 color : COLOR;
	float2 uv : TEXCOORD;
	float3 normal : NORMAL;
	float3 worldPos : WORLD_POSITION;
};

VS_OUTPUT main(VS_INPUT input) {
	VS_OUTPUT output;
	output.pos = mul(float4(input.pos, 1.0f), lwvpMatrix);
	output.color = input.color;
	output.uv = input.uv;
	output.normal = mul(float4(input.normal, 0.0f), invWorldMatrix);
	output.worldPos = mul(float4(input.pos, 1.0f), worldMatrix);
	return output;
}