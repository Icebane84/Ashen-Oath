// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "AshenGameInstance.generated.h"

/**
 * UAshenGameInstance
 *
 * Master C++ GameInstance for Ashen Oath vertical slice.
 * Manages persistent playtest session state, save game slot naming,
 * level transitions (Sanctuary Haven <-> Frozen Tarn), and system initialization.
 */
UCLASS()
class ASHENOATH_API UAshenGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UAshenGameInstance();

	virtual void Init() override;
	virtual void Shutdown() override;

	// --- Public API ---
	UFUNCTION(BlueprintCallable, Category = "AshenOath|GameInstance")
	void LaunchVerticalSliceLevel(FName LevelName);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|GameInstance")
	void SavePlaytestSession(const FString& SlotName);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|GameInstance")
	bool LoadPlaytestSession(const FString& SlotName);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|GameInstance")
	FString CurrentSaveSlotName = TEXT("PlaytestSlot_01");
};
