// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenMindscapeIdentityCompilerComponent.generated.h"

/**
 * UAshenMindscapeIdentityCompilerComponent
 * Soul component aggregating identity fragment imprints into persistent mindscape memory constellations.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenMindscapeIdentityCompilerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenMindscapeIdentityCompilerComponent();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Soul")
	int32 CompiledIdentityFragments = 0;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Soul")
	void CompileIdentityFragment(FName FragmentID);
};
