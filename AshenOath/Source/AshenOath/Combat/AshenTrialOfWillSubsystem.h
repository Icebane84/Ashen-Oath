// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Combat/AshenExistentialMeaningTypes.h"
#include "AshenTrialOfWillSubsystem.generated.h"

/**
 * UAshenTrialOfWillSubsystem
 * GameInstance Subsystem managing the 0.75-second global time dilation (0.05f scale) and stagger crisis resolution.
 */
UCLASS()
class ASHENOATH_API UAshenTrialOfWillSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Trial of Will")
	bool bIsTrialOfWillActive = false;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Trial of Will")
	float StaggerWindowDurationSeconds = 0.75f;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Trial of Will")
	float TimeDilationScale = 0.05f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Trial of Will")
	void TriggerTrialOfWill(AActor* StaggeredHero);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Trial of Will")
	void ResolveTrialOfWill(ETrialOfWillChoice Choice);
};
