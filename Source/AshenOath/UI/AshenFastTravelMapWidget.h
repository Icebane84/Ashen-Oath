// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenFastTravelMapWidget.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnFastTravelNodeSelectedSignature, FName, SelectedSanctuaryID);

/**
 * UAshenFastTravelMapWidget
 *
 * Interactive map UI backing widget for selecting unlocked sanctuary fast-travel nodes.
 */
UCLASS()
class ASHENOATH_API UAshenFastTravelMapWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void PopulateSanctuaryNodes(const TArray<FName>& UnlockedSanctuaries);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void SelectSanctuaryNode(FName SanctuaryID);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	FName SelectedSanctuaryID;

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|UI|Events")
	FOnFastTravelNodeSelectedSignature OnNodeSelected;
};
