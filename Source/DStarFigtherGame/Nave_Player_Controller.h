// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Nave_Player_Controller.generated.h"

//class ABala
//.h definiciones
UCLASS()
class DSTARFIGTHERGAME_API ANave_Player_Controller : public APlayerController
{
	GENERATED_BODY()

		//Constructor
		ANave_Player_Controller();

	UFUNCTION()
	
		virtual void SetupInputComponent() override;

protected:

 
	virtual void BeginPlay() override;

	void MoveHorizontal(float AxisValue1);
		
	void MoveVertical(float AxisValue2);


};
