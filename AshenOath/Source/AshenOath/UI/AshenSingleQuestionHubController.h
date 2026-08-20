// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Narrative/AshenPOSTypes.h"
#include "AshenSingleQuestionHubController.generated.h"

/**
 * UAshenSingleQuestionHubController
 * Controller orchestrating Single-Question Screen transitions across Kaelen's Root Journal UI Hub.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSingleQuestionHubController : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSingleQuestionHubController();

	virtual void BeginPlay() override;

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath | POS")
	FOnSingleQuestionScreenChanged OnSingleQuestionScreenChanged;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | POS")
	EAshenSingleQuestionScreen ActiveScreen = EAshenSingleQuestionScreen::ExpeditionLog;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | POS")
	void NavigateToScreen(EAshenSingleQuestionScreen TargetScreen);
};
