// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenCheatSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCheatExecutedSignature, FString, CommandName, FString, CommandArgs);

/**
 * UAshenCheatSubsystem
 *
 * GameInstanceSubsystem providing developer cheat execution across live playtest sessions:
 *   - Ashen.SetCorruption <0.0-1.0>
 *   - Ashen.TriggerCollapse
 *   - Ashen.GrantEmbers <Amount>
 *   - Ashen.UnlockAllPerks
 */
UCLASS()
class ASHENOATH_API UAshenCheatSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	// --- Console Exec Commands ---
	UFUNCTION(Exec, BlueprintCallable, Category = "AshenOath|Cheats")
	void ExecTriggerCollapse();

	UFUNCTION(Exec, BlueprintCallable, Category = "AshenOath|Cheats")
	void ExecGrantEmbers(float Amount = 1000.0f);

	UFUNCTION(Exec, BlueprintCallable, Category = "AshenOath|Cheats")
	void ExecUnlockAllPerks();

	// --- Delegates ---
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Cheats|Events")
	FOnCheatExecutedSignature OnCheatExecuted;
};
