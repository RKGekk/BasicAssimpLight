#pragma once

#include "model.h"

class GameObject {
public:
	GameObject();
	virtual ~GameObject();

	const DirectX::XMVECTOR GetPosition() const;
	const DirectX::XMFLOAT3 GetPosition3() const;
	const DirectX::XMVECTOR GetRotation() const;
	const DirectX::XMFLOAT3 GetRotation3() const;

	void SetPosition(DirectX::FXMVECTOR pos);
	void SetPosition(float x, float y, float z);
	void AdjustPosition(DirectX::FXMVECTOR pos);
	void AdjustPosition(float x, float y, float z);

	void SetRotation(DirectX::FXMVECTOR rot);
	void SetRotation(float p, float y, float r);
	void AdjustRotation(DirectX::FXMVECTOR rot);
	void AdjustRotation(float p, float y, float r);

	DirectX::XMVECTOR GetForward();
	DirectX::XMFLOAT3 GetForward3();

	DirectX::XMVECTOR GetRight();
	DirectX::XMFLOAT3 GetRight3();

	DirectX::XMVECTOR GetBackward();
	DirectX::XMFLOAT3 GetBackward3();

	DirectX::XMVECTOR GetLeft();
	DirectX::XMFLOAT3 GetLeft3();

	void SetLookAtPos(DirectX::FXMVECTOR lookAtPos);
	void SetLookAtPos(DirectX::XMFLOAT3 lookAtPos);
	void SetLookAtPos(float x, float y, float z);

	virtual void UpdateMatrix() = 0;

protected:
	DirectX::XMFLOAT3 m_pos;
	DirectX::XMFLOAT3 m_rot;

	const DirectX::XMFLOAT3 DEFAULT_FORWARD_VECTOR = { 0.0f, 0.0f, 1.0f };
	const DirectX::XMFLOAT3 DEFAULT_UP_VECTOR = { 0.0f, 1.0f, 0.0f };
	const DirectX::XMFLOAT3 DEFAULT_BACKWARD_VECTOR = { 0.0f, 0.0f, -1.0f };
	const DirectX::XMFLOAT3 DEFAULT_LEFT_VECTOR = { -1.0f, 0.0f, 0.0f };
	const DirectX::XMFLOAT3 DEFAULT_RIGHT_VECTOR = { 1.0f, 0.0f, 0.0f };
	const float EPSILON = 0.001f;

	DirectX::XMFLOAT3 m_forward;
	DirectX::XMFLOAT3 m_left;
	DirectX::XMFLOAT3 m_right;
	DirectX::XMFLOAT3 m_backward;
};