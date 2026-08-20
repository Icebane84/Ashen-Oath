// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_PressurePlateStatus.generated.h"

/**
 * UAshenUserWidget_PressurePlateStatus
 *
 * UMG backing widget rendering HUD dungeon puzzle status (Plates Depressed, Active Sequence Count, Solved Banner).
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_PressurePlateStatus : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void UpdatePlatePuzzleStatus(int32 ActivePlates, int32 RequiredPlates, bool bPuzzleSolved);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	int32 DepressedPlateCount = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	int32 RequiredPlateCount = 3;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	bool bPuzzleComplete = false;
};
