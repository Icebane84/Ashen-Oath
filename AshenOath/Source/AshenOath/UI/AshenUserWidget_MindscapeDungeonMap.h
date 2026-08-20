// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_MindscapeDungeonMap.generated.h"

/**
 * UAshenUserWidget_MindscapeDungeonMap
 *
 * UMG backing widget rendering procedural Mindscape floor maps and nightmare key locations.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_MindscapeDungeonMap : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void UpdateDungeonMapDisplay(int32 DungeonSeed, FName LayoutTheme);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	int32 DisplayedSeed = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	FName DisplayedTheme;
};
