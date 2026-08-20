// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenImprintIntegrationRitualSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnImprintPurified, int32, RemainingImprintCount);

/**
 * UAshenImprintIntegrationRitualSubsystem
 * Subsystem resolving accumulated psychological imprints back into clean FSoulStateVector traits.
 */
UCLASS()
class ASHENOATH_API UAshenImprintIntegrationRitualSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath | Soul")
	FOnImprintPurified OnImprintPurified;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Soul")
	int32 ActiveImprintCount = 0;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Soul")
	bool PurifyOldestImprint();
};
