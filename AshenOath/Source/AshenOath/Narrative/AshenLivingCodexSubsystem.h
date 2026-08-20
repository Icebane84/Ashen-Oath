// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Narrative/AshenLivingCodexTypes.h"
#include "AshenLivingCodexSubsystem.generated.h"

/**
 * UAshenLivingCodexSubsystem
 * GameInstance Subsystem managing unlocked codex entries, faction lore categorization, read states, and lore completion stat rewards (+5 Sanity/category).
 */
UCLASS()
class ASHENOATH_API UAshenLivingCodexSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Codex")
	TMap<FName, FCodexEntryData> CodexEntries;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Codex")
	bool RegisterCodexEntry(const FCodexEntryData& Entry);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Codex")
	bool UnlockCodexEntry(FName EntryID);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Codex")
	bool MarkEntryAsRead(FName EntryID);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Codex")
	int32 GetUnlockedCountForFaction(ECodexFaction Faction) const;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Codex")
	float CalculateCodexSanityReward() const;
};
