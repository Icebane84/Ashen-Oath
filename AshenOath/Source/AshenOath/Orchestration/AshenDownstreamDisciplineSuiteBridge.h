// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenDownstreamDisciplineSuiteBridge.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnDisciplineSuiteSynchronizedSignature, FName, DisciplineSuiteTag, int32, SpecificationCount);

/**
 * UAshenDownstreamDisciplineSuiteBridge
 *
 * Master subsystem bridging the 6 downstream production discipline suites: GAS, Animation, Audio, VFX/Shader, AI, UX (PRS-001 Combat Blueprint V5.0 VIII).
 */
UCLASS()
class ASHENOATH_API UAshenDownstreamDisciplineSuiteBridge : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|DisciplineSuite")
	void SynchronizeDisciplineSuites();

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|DisciplineSuite|Events")
	FOnDisciplineSuiteSynchronizedSignature OnSuiteSynchronized;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|DisciplineSuite")
	int32 TotalDisciplinesActive = 6;
};
