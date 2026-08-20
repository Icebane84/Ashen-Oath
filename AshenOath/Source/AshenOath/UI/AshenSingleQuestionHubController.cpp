// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "UI/AshenSingleQuestionHubController.h"

UAshenSingleQuestionHubController::UAshenSingleQuestionHubController()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenSingleQuestionHubController::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenSingleQuestionHubController::NavigateToScreen(EAshenSingleQuestionScreen TargetScreen)
{
	if (ActiveScreen != TargetScreen)
	{
		EAshenSingleQuestionScreen PrevScreen = ActiveScreen;
		ActiveScreen = TargetScreen;
		if (OnSingleQuestionScreenChanged.IsBound())
		{
			OnSingleQuestionScreenChanged.Broadcast(PrevScreen, ActiveScreen);
		}
		UE_LOG(LogTemp, Log, TEXT("UAshenSingleQuestionHubController: Single-Question screen shifted from %d to %d"), static_cast<int32>(PrevScreen), static_cast<int32>(ActiveScreen));
	}
}
