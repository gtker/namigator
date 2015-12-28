#pragma once

#include "LinearAlgebra.hpp"

class Camera
{
    private:
        const utility::Matrix m_projectionMatrix;

        // camera position in world coordinates
        utility::Vertex m_position;

        // point looked at by camera in world coordinates
        utility::Vertex m_target;

        // camera view up direction in world coordinate system
        utility::Vector3 m_up;

        // camera view right direction in world coordinate system
        utility::Vector3 m_right;

        float m_viewProjectionMatrix[16];

        void UpdateViewProjectionMatrix();

        bool m_mousePanning;
        int m_mousePanX;
        int m_mousePanY;

    public:
        Camera();

        void Move(float x, float y, float z);

        void LookAt(float x, float y, float z) { LookAt(utility::Vertex(x, y, z)); }
        void LookAt(const utility::Vertex &target);

        void MoveVertical(float delta);
        void MoveIn(float delta);
        void MoveRight(float delta);

        void Yaw(float delta);
        void Pitch(float delta);

        bool IsMousePanning() const { return m_mousePanning; }

        void BeginMousePan(int screenX, int screenY);
        void EndMousePan();
        void UpdateMousePan(int newX, int newY);
        void GetMousePanStart(int &x, int &y) const;

        const float *GetProjectionMatrix() const { return m_viewProjectionMatrix; }
};