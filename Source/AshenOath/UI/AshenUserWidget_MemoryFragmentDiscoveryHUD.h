// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_MemoryFragmentDiscoveryHUD.generated.h"

/**
 * UAshenUserWidget_MemoryFragmentDiscoveryHUD
 * Prompt widget displaying discovered memory fragment details and lore snippet.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_MemoryFragmentDiscoveryHUD : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	FName DiscoveredFragmentID = NAME_None;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	bool bIsPromptVisible = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void DisplayFragmentPrompt(FName FragmentID, bool bVisible);
};
