// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Combat/AshenPartySyncFinisherSubsystem.h"
#include "AshenUserWidget_PartyFinisherPromptHUD.generated.h"

/**
 * UAshenUserWidget_PartyFinisherPromptHUD
 * Dynamic finisher prompt widget showing sync partner portraits, finisher title, and input prompt.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_PartyFinisherPromptHUD : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	EAshenPartyFinisherType ActivePromptType = EAshenPartyFinisherType::None;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	FText FinisherTitle;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void DisplayFinisherPrompt(EAshenPartyFinisherType FinisherType, const FText& InTitle);
};
