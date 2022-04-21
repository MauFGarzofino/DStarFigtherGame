// Fill out your copyright notice in the Description page of Project Settings.


#include "Nave_Player_Controller.h"
#include "Kismet/GameplayStatics.h"
#include "Camera/CameraActor.h"
#include "NaveJugador.h"
//#include "Bala.h"

ANave_Player_Controller::ANave_Player_Controller()
{

}

void ANave_Player_Controller::BeginPlay()
{

	TArray<AActor*> CameraActors;

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACameraActor::StaticClass(), CameraActors);

	FViewTargetTransitionParams Params;

	SetViewTarget(CameraActors[0], Params);

}

void ANave_Player_Controller::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	EnableInput(this);
	InputComponent->BindAxis("MoveHorizontal", this, &ANave_Player_Controller::MoveHorizontal);
	InputComponent->BindAxis("MoveVertical", this, &ANave_Player_Controller::MoveVertical);

}

void ANave_Player_Controller::MoveHorizontal(float AxisValue1)
{
	auto MyPawn = Cast<ANaveJugador>(GetPawn());

	if (MyPawn) {
		
		MyPawn->MoveHorizontal(AxisValue1);

	}
}

void ANave_Player_Controller::MoveVertical(float AxisValue2)
{
	auto MyPawn = Cast<ANaveJugador>(GetPawn());
	
	if (MyPawn) {

		MyPawn->MoveVertical(AxisValue2);

	}
}
