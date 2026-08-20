// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenExistentialMeaningTypes.h"
#include "AshenKeystoneMemoryCompilerComponent.generated.h"

/**
 * UAshenKeystoneMemoryCompilerComponent
 * Implements InvokeIntegration() and CompileIdentity() at Heartstone Sanctuaries, permanently compiling character identity through trauma interpretation.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenKeystoneMemoryCompilerComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenKeystoneMemoryCompilerComponent();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Meaning")
	TArray<FMemoryEchoRecord> CompiledMemories;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Meaning")
	bool InvokeIntegration(FName MemoryID, EKeystoneInterpretiveLens Lens);
};
