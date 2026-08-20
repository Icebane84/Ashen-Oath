// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenSanctuaryHeartstoneCrucibleComponent.generated.h"

/**
 * UAshenSanctuaryHeartstoneCrucibleComponent
 * Crucible component attached to sanctuary campfires governing soul memory resonance, remnant conversion, and reflection sessions.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSanctuaryHeartstoneCrucibleComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenSanctuaryHeartstoneCrucibleComponent();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Crucible")
	bool bIsReflecting = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Crucible")
	float CrucibleResonanceMultiplier = 1.25f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Crucible")
	float CalculateResonanceEfficiency(int32 RemnantsCount) const;

	UFUNCTION(BlueprintPure, Category = "Ashen Oath | Crucible")
	bool IsReflecting() const { return bIsReflecting; }

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Crucible")
	void BeginReflectionSession();

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Crucible")
	void EndReflectionSession();

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Crucible")
	FString GenerateTelemetryPayload(const FSoulStateVector& InState);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Crucible")
	TArray<FString> GetPendingMemoryIDs() const;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Crucible")
	void FlushCompiledMemories();
};
